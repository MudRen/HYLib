 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ��");
        set("long", @LONG
�����£������ս�׵�ѩ��ΡȻ������ãã�ֺ��ϣ�������˸�������ǧ���
�ھ����۵ס��������У�������ӵ��������ţ�ǹ����˵�ɭ��ï�ܣ�Ϫ��������Ϫ
�����Ҷ������ɶ����ڴ�С����ʯ�������ɶ�ʯ�ң�����������Ļ��������ֳ�
ʯ���ҡ�
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"mount1",
                "north":  __DIR__"temple1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
