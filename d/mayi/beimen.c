inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���������صı��š��������صľ��ö༯�еĳ����ϲ�����������
�Ե÷ǳ����塣��ֵս�ң�������������ո��Ǳ�����
LONG);
set("outdoors", "mayi");
set("exits", ([
                "south": __DIR__"center",
                "north" : "/d/dingxiang/xiaolu3", 
  	]));
set("objects",([
  __DIR__"npc/bing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	replace_program(ROOM);
}	
