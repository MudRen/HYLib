// /u/beyond/ningbo/xuedoushan.c ѩ�ɽ
inherit ROOM;
void create()
{
	set("short","ѩ�ɽ");
	set("long", @LONG
������ѩ�ɽ������ɽ������������գ�ɽ����ͻ���ˣ�����ͻأ���棬
���ٷ�����ѩ����ɫ����续������������ˮ�ڽ����ػ�ۣ������¿ڶ�Ȼ
���ŭк���γɽ�����ѩ�ľ��١���̨Զ�������������羰�����㶯�ˡ�
LONG
     );
	set("exits",([ 
	//"south" : __DIR__"***",
	"north" : __DIR__"dongqianhu",
	]));
	//creat_door("
	setup();
	replace_program(ROOM);
}
