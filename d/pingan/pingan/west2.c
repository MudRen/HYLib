//yanling
inherit ROOM;
void create()
{
  set ("short", "ƽ����·");
  set ("long", @LONG
�������������߾͵���ƽ����·������ƽ���ǵ�һ���Ͻ֡����ߵķ���
����ȥ�Ѿ��ܳ¾��ˡ��ֵ��ı����һ�䷿�ӿ���ȥ��һ�����̡��������
������������������.
LONG);

set("outdoors","/d/pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  set("exits", ([  
    "north" : __DIR__"shop3",
    "south" : __DIR__"shenzhen/shenzhen",
    "east"  : __DIR__"west1",
    "west"  : __DIR__"west3",
]));
       
//	set("objects",([
//		__DIR__"npc/man4":1,
//	]));
	 setup();
        replace_program(ROOM);
}
