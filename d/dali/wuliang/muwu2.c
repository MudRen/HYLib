// Modify By River 98/12
inherit ROOM;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��ǰ��һ��ʯ�ݡ���ʯ��ģ��������֣���һ��ǧ�ٽ��صĴ�ʯ���ɣ���
��͹͹����Ȼ��һ��Сɽ�����ڱ�һ�黨�ھ��ң�yan)��ס���ұߵ���¶����
϶���е�ֻ��������е�ȴ�г߿�� 
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"muwu1",
	]));

        set("item_desc", ([
            "yan" : "����һ���ر�����ʯ����ס���ſڣ�ʹ���޷��������ڡ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_tui", "tui");
        add_action("do_tui", "push");
}

int do_tui(string arg)
{
        int i;
        i = this_player()->query("neili");
        if( !arg || arg!="yan" ) 
           return notify_fail("��Ҫ��ʲô��\n");        
          message_vision("$Nվ����ǰ����˫�Ʒ������ϣ����������һ������˫��һ���������һ����������\n", this_player());
        if (i>=800) {
          message_vision("$Nֻ��һ����죬��ʯ�������ƿ��ˣ�\n", this_player());
          set("exits/enter", __DIR__"muwu3");
          this_player()->add("neili",-800);
          remove_call_out("close");
          call_out("close", 5, this_object());
          }
        else {
          message_vision("$Nȴ����ʯ��˿����������$N��������������\n", this_player());
          this_player()->set("neili",0);
          }
    return 1;
}

void close(object room)
{
         message("vision","��ʯ�����ƶ�����ʯ���ٴη�ס�ˡ�\n", room);
         room->delete("exits/enter");
}
