// /d/gaoli/yudao8
// Room in ����
inherit ROOM;
void create()	
{
	set("short", "�ʳ�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵����
���ڲ��Ǹߴ��ΰ�Ļʳǳ�ǽ�������Ǹ�����ӭ���ݣ���������������
�����п��̣����и���ʹ�ڡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"xuanwu-1", 
                "south":__DIR__"yingbinguan", 
                "west":__DIR__"yudao6", 
                "east":__DIR__"yudao7",
	]));
       setup();
	replace_program(ROOM);
}	
