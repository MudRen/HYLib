// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ɽ��ǧ�꺮���������ķ�����������������ڱ��ϣ������
�ö��ǡ�������ͷ����ü���ۣ���С���۳մ�����ʹ����������
�ļ��̣��ñ��˵���ʧ�����Լ��Ľ������������һ�����е��ڱ���
�ߣ��������̣�����֮����Ȼ��ͬ���䡣
LONG
        );
        set("exits", ([
		"up" : __DIR__"chebeng",
		"down" : __DIR__"tuoke",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-200);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
