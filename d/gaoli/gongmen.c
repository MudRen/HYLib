// /d/gaoli/donggongmen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ʹ������ţ��������Ĺ���ֻ���ڰٹ��糯ʱ�ſ�����
���ڴ��Ž����Ĺ��ţ�һ��ʿ��Ӣ�˲�����վ�ڹ���ǰ������������ѹ
�֣�ʹ�˾����뿪��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "south":__DIR__"yudao1", 
	]));
set("objects",([
    __DIR__"npc/weishi":1,
    ]));
       setup();
	replace_program(ROOM);
}	
