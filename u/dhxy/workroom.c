// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
      set("short", "ˮ����")
;
      set("long", @LONG
�������������µ�ˮ���������ˮ�������³��ʯ�ţ����������ڱ��Ż���,
�ű��л�����������һ��ʯ��,������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ����ʯ��,
�м�һ��ʯ;���ϣ����š�����ɽ���أ�ˮ�������졣������һ����ʦ���Բ�(board)��
LONG )
;
       set("valid_startroom", 1)
;

    set("exits", ([ /* sizeof() == 1 */
     "kj" : "/d/wizard/work",
    "down" : "/d/city/guangchang",
   ]))
;
    set("no_fight", "1")
;
   set("no_clean_up", 0)
;
   setup()
;
"/u/dhxy/board"->foo()
;
  replace_program(ROOM)
;
}
