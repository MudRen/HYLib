 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ú�ׯ��Ժ");
        set("long", @LONG
�����кܿ���������������ľ���������оơ�����Ӵ����ս����������ڼ���
�������ϣ�һ����ʮ����Ĵ���������ʮ��ǰ�������������ׯ��Ѧ�������̶��
������Ѩ����ɨ������ɽ����������������Ǻ���ʮ��ǰһ����������ô�ս�����
���������ķ��Ź⡣���� ���������������أ�
LONG
        );
        set("exits", ([ 
                "east": __DIR__"xuevillage",
        ]));
        set("objects", ([
                __DIR__"npc/xuebin": 1,
                __DIR__"npc/jiaren":    1,
        ]) );
        set("coor/x",-1280);
        set("coor/y",2050);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}   
