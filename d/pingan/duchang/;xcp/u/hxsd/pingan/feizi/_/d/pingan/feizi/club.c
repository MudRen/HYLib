//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "�����ַ�ƽ���ֵ�");
        set  ("long",  @LONG
�����ǳ�����һ�����������ֳ����ķֵꡣ��ҹĻ���ٺ���
��͸������֡����������Ŀ����д�ٹ��ˣ��������������ã���
�����ĵ����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���
ɮ�˻��ʿ��
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "east" :  "d/pingan/nan2",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

