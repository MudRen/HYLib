//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "�����ַ�");
        set  ("long",  @LONG
�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ�����͸�
�����֡����������Ŀ����д�ٹ��ˣ��������������ã��˼�����
�����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���ɮ�˻�
��ʿ��
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "south" :  __DIR__"eastroad2",
              "north" :  __DIR__"qishi3",
              "west" :  __DIR__"qishi1",
              "east" :  __DIR__"qishi2",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_npc",  1);
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

