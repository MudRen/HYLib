// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�κ���");
        set("long", @LONG
�����ֻ֪���κ��ţ�ȴ��֪���κ��ţ���ʵ�κ����������κӣ��κ�
�ᴩ�ظ�������ԩ�꣬�������Ǻ���ֻ�н�ɫ���㣬����ͨ����䣬��
���칤�������̵ü�Ϊ��ϸ������Ϊ�������֡��ɴ˹�ȥ���ǵظ���
��һվ�������䡣
LONG
        );
        set("exits", ([
		"north" : __DIR__"pingan",
		"south" : __DIR__"mengpo",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-90);
	set("coor/z",-290);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
