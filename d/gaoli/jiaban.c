// Room in ����
inherit ROOM;
void create()	
{
	set("short", "�װ�");
	set("long", @LONG	
������ս���ļװ塣�м���ˮ�ֲ�ʱ���������߹�����������æµ��
������ȥ���󺣱̲����㣬һ���޼ʣ��������ʻ����ս����������һ����
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"shatan2",
		"enter":__DIR__"chuancang",
	]));
      set("objects",([
          __DIR__"npc/shuishou":1,
          ]));
       setup();
	replace_program(ROOM);
}	
