//room: /d/tangmen/xinyitang.c
//  by HEM
inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
  �����������á���ǰ�����Եľ���һ�����Ʊ��˵��ͻ���ɽͼ����˵�ǵ��꽭
���Ĵ����֮һ����������
LONG     );

  set("exits",([
      "north" : __DIR__"tianjing",
      "south" : __DIR__"changlang1",
    ]));

 setup();
}




