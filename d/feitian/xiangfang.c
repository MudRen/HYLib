// Room: /d/feitian/kefang.c
inherit ROOM;

void create()
{
  set ("short", "�᷿");
  set ("long", @LONG
��Ż��������᷿�����µ��������˿�����������Ϣһ�¡�������
���������Ѿ����������￪ʼ˯�ˣ����̲�ס���˸���Ƿ.���Ǹ�
���Ҹ�λ��˯���ɣ�
LONG);

  set("no_clean_up", 1);
        set("sleep_room", "1");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"chufang",
  "west" : __DIR__"daochang",
]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
  replace_program(ROOM);
}
