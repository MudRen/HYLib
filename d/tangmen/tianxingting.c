//room: /d/tangmen/tianxingting.c
// by HEM
inherit ROOM;

void create()
{
  set("short","����ͤ");
  set("long",
      "����һ���˽�ͤ��ͤ�������д���ʯ԰�������ʣ�������Ϣ��\n"
     );

  set("exits",([
      "north" : __DIR__"changlang21",
      "south" : __DIR__"changlang20",
    ]));

 setup();
 replace_program(ROOM);
}




