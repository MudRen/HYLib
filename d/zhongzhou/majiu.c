
inherit ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
���������ݳ�Ӣ����¥�����ǣ����깩Ӧ���ʲ��ϡ���
�ݳ��Թ��˾���Ҫ�أ���紾�ӣ�����ǻ����ǣ����Ǻ���
�տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿���
��·������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "zhongzhou");
      set("no_fight", 1);
      set("objects", ([
              "/d/city/npc/zaohongma": 1,
              "/d/city/npc/huangbiaoma": 1,
              "/d/city/npc/ziliuma": 1,
              "/d/city/npc/mafu": 1,
      ]));
      set("exits",([
              "west" : __DIR__"yinghao",
      ]));
      set("coor/x", -210);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
