// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�Ӹ���");
        set("long", @LONG
�������ǹ�ƽ���ڣ����ﷸ�������壬�ù�ƽ������ȥ�ͷ����ǣ���
���������ǵ����ģ����Եز��ص����һ���������޷�����ֻ��������
��֮�˽����ۿΣ�����������ֱ���л�Ϊֹ�����˱���������������
���ǳ��ڣ�ֱͨ�����ǡ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"abi",
		"down" : __DIR__"wangsi",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-280);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
