//room: /d/tangmen/kefang.c
//restroom
inherit ROOM;

void create()
{
  set("short","�ͷ�");
  set("long", @LONG
  ���������Ź��ÿ�ס����Ϣ�ĵط������ڻ�԰֮�У��ƴ�������,���ܿ�����԰
�ʻ����ã��ŵ��������㣬�����Ŀ�������
LONG       
     );

  set("exits",([
        "east" : __DIR__"huayuan7",
	"west" : __DIR__"huayuan6",
	"south" : __DIR__"chashi",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);

 setup();
 replace_program(ROOM);
}





