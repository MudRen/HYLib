// Room in ����
inherit ROOM;
void create()	
{
	set("short", "�ݵ�");
	set("long", @LONG	
������һƬ��ݵء��ݵ��������ɣ���������ǳ��������������
�ֻ��ƣ��������£���ɫ������������һ����Ժ����������ģ���Ǻܴ�
���洫���о���������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southeast" : __DIR__"suishilu2",
		"west":__DIR__"miaodoor",
       	]));
       setup();
	replace_program(ROOM);
}	
