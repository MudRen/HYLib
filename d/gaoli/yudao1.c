// /d/gaoli/yudao1
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ʳ�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵����
���ڲ��Ǹߴ��ΰ�Ļʳǳ�ǽ������ͨ��ʳǵ����ţ���������Χ�ƻ�
���Ļʳ�������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"gongmen", 
                "south":__DIR__"zhuque-1",
                "west":__DIR__"yudao2",
                 "east":__DIR__"yudao3",
	]));
       setup();
	replace_program(ROOM);
}	
