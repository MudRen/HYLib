#include <ansi.h>
inherit ROOM;
string script();
void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ�ѧʿ������������ƽ���ռ��������׵����ڡ�����������ʱ׫д����
���书�ĵá�������ʰ�øɾ����࣬���ݵ�����϶������鼮���������Ų������
�Ʒ������������һ���ָ塣 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"shufang",
        ]));

        set("no_fight", 1);
        set("no_magic", 1);
    set("coor/x",40);
    set("coor/y",1870);
        set("coor/z",0);
        setup();
} 
