// Room in ����
inherit ROOM;
void create()	
{
	set("short", "�ڿ�");
	set("long", @LONG
	
��������ʯ���������һ���ڿ����㻹û�п��������˴󺰽���ͣ
�����㿴��ʿ�����ϵļ�����Ͻ�ת������ߡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		//"north" : __DIR__"tulu2",
		"southwest" : __DIR__"sanchalu",
	]));
       setup();
	replace_program(ROOM);
}	
