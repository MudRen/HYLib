// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
            set("short", "�η���Ϣ��");
	set("long", @LONG
�����ǹη����Ϣ��������װ�޵ķ��ӣ���û��ʲô�Ҿߡ���
�ӳ����ķ�����һ��������ش��������������ͨ������������
�������䡣�����ӵĶ�����һ�Ŵ�������ͨ�Ĵ�������ı��ӵ���
�������룬���ĳ������Ǹ�����������ˡ�


LONG );

	set("exits", ([ /* sizeof() == 1 */
                  "down" : "/d/city/guangchang",
            "wl" : "/d/wizard/wizard_room",
              "lj" : "/u/guaf/lujing",
	]));
                set("objects",([
      "/clone/gem/zhang" : 1,
    ]));
//        set("no_fight", "0");
	set("no_clean_up", 0);
        set("valid_startroom", "1");
	setup();

        call_other("/u/guaf/guaf_b", "???");
	replace_program(ROOM);
}
