inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǿ͵�����ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ��
��ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź�
������·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "city");
      set("no_fight", "1");
      set("no_beg", "1");
      set("no_clean_up", 0);
      set("objects", ([
               "/d/city/npc/zaohongma": 1,
               "/d/city/npc/huangbiaoma": 1,
               "/d/city/npc/ziliuma": 1,
               "/d/city/npc/mafujingzhou": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����ʮ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  yz
          ������:  km
          �ɶ���:  cd

TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"kedian",
      ]));
      setup();
      replace_program(ROOM);
}

