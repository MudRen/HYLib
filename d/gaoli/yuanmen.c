// Room in ����
inherit ROOM;
void create()	
{
	set("short", "ԯ��");
	set("long", @LONG
	
���ǰټ�פ�����ڵı�Ӫ��ԯ�ţ����������ɸߵ���ˣ�����ϵ�
���ϣ�ԯ�ŵ����԰ټ�ʿ�������Դ�������ǰ�߾��Ǳ�Ӫ���о�����
�ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"dadao5",
		"south" : __DIR__"dazhang",
	]));
       setup();
	replace_program(ROOM);
}	
