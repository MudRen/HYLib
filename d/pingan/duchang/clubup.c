/*  <SecCrypt CPL V3R05>  */
 
//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "ƽ���ֵ��¥");
        set  ("long",  @LONG 
�ַ�¥���Եø������֣���������������������������������
�ӣ���ǩ����Ǯ�����̵����������������ӣ������Ƕĵ������ء�
LONG); 
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
        set("exits",  ([  //sizeof()  ==  4
                "up"  :  __DIR__"club3",
		"west"  :  __DIR__"duchang1",
                "east"  :  __DIR__"duchang2",
//                "north"  :  __DIR__"duchang3",
                "south"  :  __DIR__"duchang4",
                "down"  :  __DIR__"club",
        ]));

        set("objects",  ([  //sizeof()  ==  1
//               __DIR__"npc/libai"  :  1,
                 __DIR__"obj/tables"  :  3,
        ]));


//      set("outdoors",  "changan");
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

