//room: /d/tangmen/mubian.c
// by HEM
inherit ROOM;

void create()
{
	set("short","�Һ�");
	set("long",
        "�����ҵĺ��棬���������ҳ����������ӵ��˵������ֺ�����ʲô������\n"
     );

	set("exits",([
		"down" : __DIR__"jizuting",
      ]));
	set("objects",([
		__DIR__"obj/anqibook" : 1,
	]));


 setup();
 replace_program(ROOM);
}




