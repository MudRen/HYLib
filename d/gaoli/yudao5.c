// /d/gaoli/yudao5
// Room in ����
inherit ROOM;
void create()	
{
	set("short", "�ʳ�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵����
���ڲ��Ǹߴ��ΰ�Ļʳǳ�ǽ�������Ǹ�������ʿ�йݣ����������Ķ�
��һЩ��������ʿ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"yudao7", 
                "south":__DIR__"yudao3", 
                "east":__DIR__"baihu-1", 
                "west":__DIR__"xingguan",
	]));
       setup();
	replace_program(ROOM);
}	
