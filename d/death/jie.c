// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ����˾");
        set("long", @LONG
�Թ���������Ů������������أ�����Ů�ӣ��������ջ���
�����ѣ����ǵ�����ʬ֮�ࡣ��˾���Ծ������Ů�ӵĻ��񣬻���
�д�ӵ��һλŮ�Ӷ������ϣ����ǽ�˾���ƹ�--���飬��������Ϊ
ʯ����檣��������������ˣ�����¥����������֮��������ǧ�š�
�����â֮�У����ܷ�ʬ֮�̵�����ŮŮ����Ϊ��ª��
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/greengirl":1,
        ]) );
	set("coor/x",-1030);
	set("coor/y",-30);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
