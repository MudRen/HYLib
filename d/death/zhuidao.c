// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "׵����");
        set("long", @LONG
ӭ����Ǽ������ˣ��ֳִ�׵�������޴�����Ƶ�ҩ���ƵĶ�������
�ƺ��вҽ�֮������������ϸ����ԭ�����������Ž�ȥ���ɾ��˵�Ϊ
���࣬����������״����������ࡣ���ƶ�ͷ���뱨������֪
���գ��αص����������˶�������Ȼ�����򳵱�����
LONG
        );
        set("exits", ([
		"up" : __DIR__"moai",
		"down" : __DIR__"chebeng",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-180);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
