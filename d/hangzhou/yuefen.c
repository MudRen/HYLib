// yuefen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
Ĺ��������ʯ����ʯ��ʯ����������١����йŰؽ��£��������ɵķ�Ĺ��
Ĺ�����š���������Ĺ���� ����Ĺ�����棬��������֮�����Ƶ�Ĺ��Ĺ����
���š��μ��Һ�����֮Ĺ��.  ������ǰ�������ĸ�����(statue)������ǽ��
���ĸ�����(word)��
LONG);
        set("exits", ([
            "south"     : __DIR__"yuelang",
        ]));
        set("item_desc" , ([
            "statue" :
"�����������ػ�������������ϣ��ϱ�������ͬıɱ�����ɵļ鳼��
�ſ�����ٹм���ĸ����񶼷������֣�����Ĺ���š��������˵�����(tuo)��\n",
            "word"   :
"ǽ���С����ұ������ĸ����֡�������ĸ����ѵ��ʱ�����ɱ��Ͽ̵��֡�\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
//        replace_program(ROOM);
}
void init()
{
   add_action("do_spit","spit");
   add_action("do_spit","tuo");
   add_action("do_spit","��");
}
int do_spit(string arg)
{
   if( !arg || arg=="" ) 
{
message_vision("$NҪ��ʲô��?��\n", this_player());
   return 1;
}
   if( arg=="statue" )
   {   switch (random(4)) {
   	 case 0:
		message_vision("$N���ػ�������һ�ڣ�����������鳼 *&#$%����\n", this_player());
		break;
	 case 1:
		message_vision("$N������������һ�ڣ��������������������Ϊ潣�����������\n", this_player());
		break;
	 case 2:
		message_vision("$N���ſ�������һ�ڣ��������Ϊ����潣��ݺ���������\n", this_player());
		break;
	 case 3:
		message_vision("$N����ٹм������һ�ڣ��������Ϊ����潣��ݺ���������\n", this_player());
		break;
   }
   return 1;
}
}
