#include <QCoreApplication>
#include <iostream>

#include<observer.h>
#include<map>
#include<array>

namespace TESTS {

void attachDetachTest() {
    std::map<QString, Stream*> mapOfStream;
    std::array<QString, 10> cameraIpArray {
            "172.16.30.30", "172.16.30.31", "172.16.30.32", "172.16.30.33", "172.16.30.30",
            "172.16.30.30", "172.16.30.30", "172.16.30.32", "172.16.30.32", "172.16.30.34"
        };

    std::array<QString, 10> streamIdArray {
            "0x000", "0x001", "0x002", "0x003", "0x004",
            "0x005", "0x006", "0x007", "0x008", "0x009"
        };

    Stream* stream;
    Observer* observer;

    auto printLambda = [&mapOfStream](){
        std::cout << "mapSize: " << mapOfStream.size() << std::endl;
        for(auto [key, value] : mapOfStream) {
            std::cout << "key: " << key.toStdString() << std::endl;
            std::cout << "streamCount: " << value->getStreamCount() << std::endl;
            for(auto item : mapOfStream[key]->getListOfObserver()) {
                (item)->callStream();
                (item)->callObserver();
            }
        }
        std::cout << std::endl;
    };

    for(int kk = 0; kk < (int)cameraIpArray.size(); ++kk) {
        std::cout << "Stream id: " << cameraIpArray.at(kk).toStdString() << std::endl;
        // C++20 feature map.contains()
        if(!mapOfStream.contains(cameraIpArray.at(kk))) {
            stream = new Stream();
            mapOfStream.insert_or_assign(cameraIpArray.at(kk), stream);
            observer = new Observer(mapOfStream[cameraIpArray.at(kk)], streamIdArray.at(kk));
        }
        else {
            observer = new Observer(mapOfStream[cameraIpArray.at(kk)], streamIdArray.at(kk));
        }
    }

    printLambda();

    // Detach one observer from proper stream. (172.16.30.31 Ip - 0x001 Id)
    QString detachIp = "172.16.30.31";
    QString detachId = "0x001";

    Stream* properStream = mapOfStream[detachIp];
    for(auto item : properStream->getListOfObserver()) {
        if(item->getStreamId() == detachId) {
            item->removeObserverFromStream();
            if(properStream->getStreamCount() == 0) {
                mapOfStream[detachIp] = nullptr;
                mapOfStream.erase(detachIp);
            }
        }
    }

    printLambda();

    delete observer;
    delete stream;
}

} // TESTS

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;
    TESTS::attachDetachTest();

    return 0;
}
