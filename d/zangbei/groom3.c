 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�෿");
        set("long", @LONG
���㴨�����Ӿ��¶��ɾ���ÿ��������ǡ������Ӧ���ڵĵط���������ʲô��
�����Ҳ������ҳ���������������һ�������ࡢ�򵥡����ء������񡰶��ࡱ����
����������£��Ӳ�Ҫ�����װ�Σ�Ҳ�Ӳ�˵����Ļ�����Ϊ��������˷ѡ�ֻ��
�޴����˲��˷ѡ��ƹ�������������￴������������Ĳ����Ǹ��ҡ�
LONG
        );
        set("exits", ([ 
                "south" :       __DIR__"garden4",
                "west":         __DIR__"kitchen", 
        ]));
        set("objects", ([
                __DIR__"npc/lv":        1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
