//Cracked by Kafei
// group bwdh/wizroom
// Apache 09/29/98

inherit ROOM;

string look_note();

void create() {
    set("short", "�Խ�ɽׯ������");
    set("long", @LONG
�������Խ�ɽׯ�����˾�ס�ĵط���������Ҳ���Ը��
�����Խ�ɽׯ��ǽ�Ϲ���һ����(note)��������ע�⡣����
����Ķ������Ǹ����˳Ծ���
LONG
    );
    set("exits", ([
        "square"  : __DIR__"square",
        //"skantai" : __DIR__"kantai_s",
        //"nkantai" : __DIR__"kantai_n",
        "eastxf"  : __DIR__"east_xiangfang",
        "westxf"  : __DIR__"west_xiangfang",
        "center"  : __DIR__"room_28",
        //"dc"  : __DIR__"gamble_room",
    ]));
    set("objects", ([
        __DIR__"obj/casino" : 1,
//        __DIR__"obj/control"     : 1,
        __DIR__"obj/microphone"  : 1,
    ]));
    set("item_desc", ([
        "note" : (: look_note :),
    ]));
    setup();
}

void init() {
    object me = this_player();
    if ( !wizardp(me) )
        me->move("/d/death/blkbot");
}

string look_note() {
    string msg;

    msg = "
һ������Ĳ�������
  1. assign group entrance (assign n east/west)
<after they all enter>
  2. duet init (need dispatch camera team here, so be sure all ppl entered)
  3. casino set ratio (casino east/west n)
  4. casino bet
  5. casino stop
  6. duet start
  7. judge east/west/tie
  8. casino east/west/ 0 (set winner)
  9. casino pay
 10. casino stop
�����ο�������\n";

    return msg;
}