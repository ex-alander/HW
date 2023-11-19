#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <thread>
#include "Main Functions.h"
#define __STDC_WANT_LIB_EXT1__ 1
using namespace std;

int main()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /*TEXTS FOR TESTING*/
    // length = 1000, repeats every 10 chars
    //const string text = "You better lose yourself in the moment you own it";
    //const string pattern = "you";
    // length = 11400, no stable repeats
    //const string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent sit amet sapien eget erat tempor sodales eget in odio. Sed sit amet ligula mollis, malesuada metus vel, porttitor metus. Aenean sollicitudin tempor nibh, ut tincidunt augue mattis sed. Vestibulum dignissim orci sed ornare dignissim. Donec eleifend ante leo, nec convallis risus posuere id. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nulla eget velit quis lectus dignissim rutrum. Pellentesque elementum nisl a dapibus blandit. Sed accumsan, purus sed efficitur euismod, odio lacus aliquam metus, et molestie risus mauris interdum sem. Aliquam malesuada nunc risus, ac auctor libero varius sit amet. Morbi vitae pharetra nisi. Maecenas gravida eu lorem et dignissim. Praesent bibendum mauris vel enim facilisis posuere. Ut ultrices placerat diam at consectetur. Aenean a eros erat. Phasellus elit elit, venenatis sed turpis ut, consequat posuere eros. Phasellus sit amet varius tellus. Nam luctus risus at est tempor lobortis. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Sed ac lectus pharetra, varius lacus et, lacinia lorem. Nam lobortis enim erat, eget pellentesque sem volutpat quis. Nam aliquet maximus congue. Suspendisse ut libero sapien. Integer sed eleifend enim, ut auctor libero. Suspendisse id felis ultrices, accumsan diam sed, hendrerit mauris. Quisque mollis dolor a nibh dignissim, sed dapibus metus dictum. Sed suscipit urna non ex interdum viverra. Nam aliquet non dui volutpat ultrices. Nullam sit amet tempor lacus. Nunc maximus neque nisi, a gravida purus facilisis ut. Donec scelerisque turpis risus, sit amet accumsan augue maximus non. Donec eget fermentum ex, non egestas massa. Suspendisse mollis, est quis efficitur tempus, mi magna pulvinar odio, sed dictum lectus mi vitae neque. Nunc iaculis, orci nec placerat placerat, elit sem mollis justo, interdum ullamcorper nibh eros eget ligula. Aenean suscipit elit at nibh finibus, eu blandit augue imperdiet. Maecenas porttitor molestie sapien, vitae eleifend mi tincidunt ac. Morbi rhoncus magna sed turpis lobortis, ornare convallis metus sodales. Nam congue faucibus dapibus. Vestibulum blandit leo ex, ut lobortis lacus congue quis. Nam et mauris eu lectus consequat eleifend tempor vitae libero. Suspendisse nunc orci, rutrum eu iaculis quis, egestas a nisi. Quisque vestibulum, turpis sed viverra pharetra, mi quam sodales turpis, sit amet mattis lectus erat quis tellus. Etiam sollicitudin nisl purus, ut consectetur sem blandit sit amet. Donec et fringilla tellus. Praesent aliquet nec nisi in feugiat. Ut leo erat, porta ac nisi in, dictum porttitor eros. Donec quam metus, egestas vitae dui id, tempus porta felis. Fusce eleifend finibus malesuada. In eget erat at velit tempus scelerisque. Nam id rutrum nisi. Vestibulum mi velit, aliquet sed neque nec, volutpat rutrum sem. Vivamus scelerisque pharetra metus sit amet sodales. Praesent faucibus odio mauris, eget varius magna ullamcorper eu. Nunc et pretium lacus. Duis imperdiet lacinia risus, rutrum bibendum ante bibendum auctor. Quisque interdum ante consectetur ante dignissim, et blandit enim congue. Sed dapibus turpis quis leo condimentum tincidunt. Donec viverra eros sit amet auctor efficitur. Suspendisse ut mauris sapien. Pellentesque a faucibus magna. Aliquam velit urna, finibus ut dui non, vulputate sodales diam. Fusce pretium gravida pellentesque. Quisque interdum gravida erat, sed vestibulum tortor convallis nec. Sed porta mi ut feugiat scelerisque. Donec facilisis velit ut dolor tincidunt dapibus non nec massa. Ut facilisis luctus ligula, semper volutpat nibh tincidunt sit amet. Curabitur in quam nunc. Duis condimentum neque nec pharetra fermentum. Aliquam non iaculis lectus, porta tristique tortor. Duis congue tortor eget nisi pretium, vel aliquet mi euismod. Nulla quis mattis ante. Pellentesque sit amet quam ac lectus sodales interdum non euismod neque. Nulla dictum a velit in fermentum. Aliquam erat volutpat. In hac habitasse platea dictumst. Duis tincidunt id magna tincidunt lacinia. Sed nulla sem, maximus vitae tincidunt id, fermentum sit amet dolor. Sed non odio at libero efficitur auctor. In risus lectus, molestie eu pharetra eget, maximus a lacus. Etiam in venenatis dolor. Nunc nec hendrerit velit. Pellentesque ac laoreet nisl. Duis luctus interdum lacus, vel placerat velit pretium sit amet. In pretium molestie efficitur. Etiam fermentum risus sit amet tempor fermentum. Integer mi arcu, rutrum non erat tempor, porttitor consequat purus. Etiam elementum semper neque, ut vehicula odio tincidunt a. Nunc pulvinar id augue quis mattis. Fusce a viverra dolor. Nam cursus rutrum risus quis sodales. Vestibulum in purus enim. Nam nisi velit, ullamcorper tincidunt porttitor nec, sodales nec sapien. Aliquam tempor, metus nec malesuada lobortis, nunc lacus vestibulum purus, sit amet commodo dolor justo sed velit. Sed vitae consectetur orci. Mauris quis egestas erat. Phasellus cursus congue tortor ut bibendum. Sed nec mollis libero. Phasellus a malesuada elit, gravida consequat quam. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Donec dapibus orci vitae neque ornare tincidunt. Sed accumsan vestibulum sollicitudin. Pellentesque ullamcorper, est sed interdum faucibus, justo ipsum vestibulum lectus, ut sollicitudin diam ipsum ut nulla. Nulla nulla purus, ornare ut scelerisque rutrum, condimentum ut tellus. Nam egestas nunc sed lorem semper, sit amet tempor ex tempus. Suspendisse potenti. Nulla tempus pulvinar lacus at lobortis. Curabitur accumsan, diam nec tempus posuere, mauris ligula lacinia magna, varius elementum dolor erat et ante. Nulla sagittis dui enim, sit amet blandit est vehicula vitae. Donec euismod posuere maximus. Maecenas molestie massa lorem, pharetra elementum odio convallis ut. Ut tempus lectus eget nibh euismod, vitae ultricies elit fringilla. Ut commodo, augue sed pretium dapibus, augue enim pulvinar tortor, fringilla tempor orci nisi a erat. Aenean blandit eu mi non viverra. Morbi efficitur vestibulum feugiat. Maecenas dictum feugiat condimentum. Sed molestie diam eu metus consectetur, imperdiet dignissim ex cursus. Suspendisse pulvinar semper neque, finibus ullamcorper nulla. Integer pretium suscipit nunc sit amet accumsan. Integer ut convallis dui. Curabitur ut sem bibendum, euismod nunc ullamcorper, convallis mauris. Sed tempus eget magna vel pretium. Sed blandit augue eget nisl varius, ac semper neque dapibus. Proin sit amet semper ipsum. Proin risus lorem, imperdiet vel lacus in, tempus posuere nulla. Duis eu scelerisque enim. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Vivamus cursus metus pulvinar suscipit facilisis. Mauris elementum semper elit, sed imperdiet diam varius sed. Vestibulum at justo eleifend, vulputate est ac, dapibus metus. Sed ex enim, tempor ut neque et, lobortis pellentesque augue. Morbi sit amet sapien bibendum, lacinia augue sed, mollis nisl. Maecenas quis lacus sem. Aenean quis orci turpis. Mauris facilisis semper pretium. Maecenas posuere tortor at mauris tincidunt sodales. Suspendisse ligula magna, interdum iaculis eros eu, euismod convallis magna. In et pellentesque risus. Sed quis dui risus. Nam ultricies mattis rhoncus. Suspendisse pellentesque felis et leo aliquet, tristique mattis augue gravida. Morbi lectus lorem, efficitur nec tempor sit amet, scelerisque quis tortor. Quisque sodales dolor quis sapien dictum, vitae rutrum odio ultricies. Aenean condimentum iaculis lectus ut rutrum. Suspendisse consectetur facilisis leo, sed varius velit sollicitudin eu. Integer lacus felis, condimentum et lorem vitae, elementum faucibus massa. Nulla consectetur ex ut tempor molestie. Cras eget pellentesque velit, eu facilisis tortor. Nunc in augue sed mi pulvinar facilisis. Maecenas a eleifend lectus. Aliquam interdum suscipit orci, molestie tristique lectus pretium vitae. Donec molestie purus vel nulla imperdiet, sed ornare libero pulvinar. Vivamus ultricies egestas diam, non lobortis tellus tempus eu. Suspendisse potenti. Nulla tempor ligula nibh, quis sodales mauris consequat id. Phasellus finibus id purus vel condimentum. Cras id auctor tortor. Donec dignissim, nisi eu pulvinar congue, turpis arcu fermentum velit, vitae dapibus elit turpis luctus velit. Maecenas dolor dolor, varius non lacus eu, efficitur facilisis mauris. Donec ac lacinia quam, nec sollicitudin est. Quisque fermentum arcu sit amet orci tempor, sit amet aliquet diam tempor. Praesent vehicula tempus neque vitae sollicitudin. Phasellus non sollicitudin augue, in interdum purus. Pellentesque scelerisque lorem non massa scelerisque pulvinar. Pellentesque in semper lacus. Donec efficitur porta massa, id varius urna faucibus at. Integer posuere eros magna, sit amet gravida nibh sodales quis. Pellentesque scelerisque malesuada dolor dignissim viverra. Cras placerat elit elit, id ultricies turpis placerat at. Proin id condimentum lacus. Pellentesque eu nunc ac lorem congue dictum. Vivamus malesuada quis urna at suscipit. Integer euismod turpis erat, ac facilisis magna semper ut. Mauris a ipsum vitae tortor semper pretium. Sed rhoncus, lacus at egestas ullamcorper, lorem tellus scelerisque sem, quis elementum nisi erat vitae metus. Aliquam facilisis, nulla vitae commodo fermentum, dui nisl ultrices leo, vel euismod purus libero at dolor. Donec iaculis ut tellus accumsan lacinia. Integer sit amet dapibus ipsum. Integer consectetur mauris ornare felis viverra, nec congue mauris dignissim. Integer dignissim velit lectus, quis aliquet libero sollicitudin non. Etiam faucibus tellus sit amet felis commodo, nec rhoncus diam pulvinar. In malesuada arcu vitae dui condimentum convallis vitae ac lacus. Sed fermentum dapibus felis at aliquam. Maecenas venenatis varius dui in viverra. Aliquam scelerisque elit magna, ut rhoncus odio tristique in. Cras sit amet rutrum turpis. Etiam mattis, mauris ac dapibus mattis, lacus massa posuere lorem, at sodales dolor nibh in arcu. Aenean eu sem suscipit, lobortis mi non, tincidunt risus. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Cras mattis semper tempor. Vestibulum commodo felis quam, vel scelerisque neque rhoncus quis. Fusce viverra congue erat. Aliquam dapibus varius tellus, a tincidunt ipsum accumsan ac. Donec at porta massa. Mauris in rhoncus arcu. Pellentesque rutrum congue ante, eget sollicitudin quam efficitur a. Ut ligula elit, faucibus placerat commodo et, tincidunt eget lectus. Nulla mattis imperdiet venenatis. Aenean ullamcorper convallis justo vel fringilla. Suspendisse consectetur diam non quam sollicitudin placerat. Fusce vulputate id risus non finibus. Curabitur luctus felis sit amet velit molestie varius. Curabitur mollis vitae leo non convallis. Curabitur semper velit dignissim magna commodo tincidunt. Nunc mattis blandit egestas. Fusce odio nulla, dapibus sed nisi viverra, vulputate faucibus nunc. Ut et est sit amet orci posuere congue. Curabitur ac nunc at risus malesuada congue. Duis felis dui, malesuada vel commodo a, finibus id lectus. Proin urna mi, porta non scelerisque nec, hendrerit molestie dolor. Aliquam laoreet, magna id tincidunt tempor, lorem quam eleifend felis, non scelerisque libero lacus sed libero. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam eget pretium diam. Ut auctor libero vitae tempor placerat. Pellentesque eu ante at sapien efficitur ultricies. Ut sit amet pellentesque neque. Proin eleifend eget est in aliquam. Morbi aliquam bibendum egestas. Nunc imperdiet accumsan felis, id lacinia ligula ultricies sed. Aliquam a odio vel turpis cursus porttitor malesuada ut lacus. Fusce consectetur nisi pretium tristique condimentum. Phasellus sollicitudin, lacus ut facilisis auctor, sem eros hendrerit est, et molestie elit magna eget ex. Vivamus a accumsan sem. Nullam elementum pretium metus, ut efficitur eros vestibulum eu. Nunc auctor, arcu nec convallis sollicitudin, tellus sem maximus massa, eget faucibus quam neque a felis. Integer sed metus blandit, viverra diam ac, gravida dolor. Etiam blandit augue quis ante luctus, a consectetur erat gravida. In ut sem lacus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean venenatis velit eget urna mattis maximus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed accumsan, odio sit amet faucibus placerat, nibh eros hendrerit sem, ut pellentesque dolor nunc ut libero. Nunc maximus, erat vel vulputate venenatis, magna nibh vestibulum dui, suscipit gravida lorem ex non odio. Ut velit diam, finibus vel dui ut, ornare maximus augue. Curabitur elit lorem, efficitur nec ullamcorper non, molestie vitae urna. Sed fringilla scelerisque libero, ut pharetra eros convallis in. Duis at mattis augue, viverra congue turpis. Praesent ut enim consequat, venenatis nisi nec, commodo dolor. Phasellus ut aliquam odio. Etiam vehicula purus dui, et finibus neque vestibulum nec. Ut finibus vehicula iaculis. Aliquam molestie gravida ante, et luctus augue accumsan placerat. Morbi lacinia sed velit sit amet tempor. Maecenas vel tincidunt urna. Praesent hendrerit justo non libero cursus, a iaculis ex blandit. Donec magna sapien, convallis sit amet posuere vel, sollicitudin vel leo. Sed accumsan porta nisi, eu viverra lorem. Praesent ipsum nibh, aliquam at arcu sed, consectetur dapibus mi. Donec sit amet orci volutpat, semper augue sed, efficitur tellus. Quisque dolor mauris, elementum in semper et, luctus eget metus. Curabitur mi turpis, ultrices sit amet ex at, lacinia ultricies tortor. Nullam pretium quam ac massa tincidunt mollis. Proin velit metus, mattis in hendrerit id, suscipit et lectus. Pellentesque venenatis iaculis nibh, vel venenatis ipsum gravida id. Phasellus vel tellus in quam tristique tristique. Duis urna ipsum, vehicula at ex eu, rhoncus sodales nisi. Duis suscipit dapibus consectetur. Fusce odio ex, vestibulum ac ligula ut, scelerisque tempor tortor. Aliquam nec massa quis ante mattis dignissim a id risus. Nullam fermentum mi sed diam pulvinar, a iaculis metus varius. Etiam varius placerat tempor. Cras dignissim enim sollicitudin sem posuere scelerisque. Ut venenatis eget ligula eget egestas. Phasellus viverra augue quis tempor lobortis. Aliquam porta malesuada velit. Duis laoreet interdum turpis nec iaculis. Sed porta pharetra leo. Suspendisse dictum dapibus ligula vitae dapibus. Sed blandit in sapien in iaculis. Phasellus pharetra id lectus quis aliquet. Etiam laoreet laoreet accumsan. Fusce sodales orci purus, id pretium ligula aliquet a. Cras pellentesque molestie malesuada. Nam sed nisi elementum, tincidunt eros ut, faucibus tortor. Sed in cursus elit, at volutpat augue. Nulla facilisi. Nulla blandit tortor eu efficitur maximus. In non nunc vel massa aliquet suscipit vitae et lorem. Donec arcu lorem, posuere sit amet lacus vel, dignissim fermentum justo. Donec maximus enim vel elementum vestibulum. Proin volutpat laoreet ipsum. Suspendisse nec dolor quam. Duis efficitur fringilla tortor, et maximus enim cursus ut. Proin bibendum vehicula posuere. Suspendisse fringilla nulla sed cursus facilisis. Morbi eu nisl rutrum, rhoncus nunc ac, interdum erat. Proin in dui diam. Nulla tempor efficitur nisi, sed accumsan nunc consequat quis. Fusce at fringilla urna. Fusce sed sodales quam, elementum commodo neque. Pellentesque varius venenatis arcu, vitae volutpat nunc faucibus pretium. Ut aliquet ornare sem et tincidunt. Ut facilisis, libero ac convallis porta, tortor turpis fringilla mauris, ut venenatis turpis massa eget nisl. Proin vitae mauris est. Quisque pretium tellus a tristique consequat. Curabitur vel nulla sit amet ex porttitor rhoncus non nec nulla. Maecenas at velit turpis. Nunc non faucibus magna, eget ultricies purus. Maecenas id luctus erat. Vestibulum ut vulputate lectus. Ut leo nisi, tincidunt in erat eget, tincidunt auctor dui. Nulla eget erat magna. Ut quis fermentum massa, a auctor ligula. Cras viverra libero quis nunc condimentum, non mattis mauris congue. Pellentesque semper sed urna in hendrerit. Sed porta odio a placerat luctus. Sed pulvinar nisi a quam sollicitudin, vel pulvinar mi consequat.";
    
    // length = 20, no stable repeats
    //const string text = "Well, Prince, so Genoa";

    // length = 1000, 1 stable repeat - the whole text
    const string text = "“Well, Prince, so Genoa and Lucca are now just family estates of the Buonapartes. But I warn you, if you don’t tell me that this means war, if you still try to defend the infamies and horrors perpetrated by that Antichrist—I really believe he is Antichrist—I will have nothing more to do with you and you are no longer my friend, no longer my ‘faithful slave,’ as you call yourself! But how do you do? I see I have frightened you—sit down and tell me all the news.” It was in July, 1805,hey what's up“Well, Prince, so Genoa and Lucca are now just family estates of the Buonapartes. But I warn you, if you don’t tell me that this means war, if you still try to defend the infamies and horrors perpetrated by that Antichrist—I really believe he is Antichrist—I will have nothing more to do with you and you are no longer my friend, no longer my ‘faithful slave,’ as you call yourself! But how do you do? I see I have frightened you—sit down and tell me all the news.” It was in July, 1805,hey what's up";
    //const string text = "qwertyuiopqwertyuiopqwer qoidnwoinas noian oisa sdoia ndoisa sanoi qwertyuiopqwer";

    //text length for testing
    //cout << text.length() << endl << endl;

    /*PATTERNS FOR TESTING*/
    /*long->repeats_yes*/
    //const string pattern = "oi"; // for qwertyuiop text // scores 73 times on a 11400 text 
    //cout << pattern.length() << endl << endl;
    /*long->repeats_no*/
    //const string pattern = "qwertyuiopqwer"; // for qwertyuiop text
    
    /*short->repeats_yes*/
    const string pattern = "l"; // for War&Peace text // scores 45 times on a 11400 text 
    //const string pattern = "ss";
    //const string pattern = "nn";

    /*short->repeats_no*/
    //const string pattern = "q"; //for qwertyuiop text, 100 times
    //const string pattern = " "; // scores 2014 times on a 11400 text  
    //const string pattern = " "; // scores 726 times on a 11400 text 
    cout << "INPUT STRING (TEXT):       " << text << "\n"
        << "STRING TO SEARCH (PATTERN): " << pattern << "\n\n";

    // check if the pattern isn't bigger than the text
    if (pattern.length() > text.length())
    {
        SetConsoleTextAttribute(hConsole, 4);
        divide();
        cout << "WRONG INPUT\n";
        divide();
        SetConsoleTextAttribute(hConsole, 15);
        return 0;
    }

    // Naive
    divide();
    SetConsoleTextAttribute(hConsole, 15);
    cout << rectangle("Naive") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    auto start = chrono::high_resolution_clock::now();
    searchNaive(text, pattern);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "time consumption: " << elapsed.count() << " ms" << endl;
    divide();

    // Knuth-Morris-Pratt
    SetConsoleTextAttribute(hConsole, 14);
    cout << rectangle("Knuth-Morris-Pratt") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    KMPSearch(text, pattern);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() << " ms" << endl;
    divide();

    // Boyer Moore
    SetConsoleTextAttribute(hConsole, 12);
    cout << rectangle("Boyer-Moore") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    BW(text, pattern);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() << " ms" << endl;
    divide();

    // Rabin Karp
    SetConsoleTextAttribute(hConsole, 3);
    cout << rectangle("Rabin-Karp") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    rabinKarp(text, pattern);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() << " ms" << endl;
    divide();

    // Shift-Or
    SetConsoleTextAttribute(hConsole, 10);
    cout << rectangle("Shift-Or") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    Silakov(text, pattern);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() << " ms" << endl;
    divide();
}
