//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "����������");
        set  ("long",  @LONG
������ǳ�������----�����š�����Ϊ�೯�Ŷ�����Ȼ��ͬ���죬
��ǽ��ʯ�ҡ�Ŵ�׺������ɣ��������������������ű��ֱͨ���ݣ���
���ٱ��������š�
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
            //"north"  :  "/d/changan/ca34",
            //"west"  :  "/d/xingxiu/xxroad1",
            "south"  :  __DIR__"apanggong",
            "west"  :  "/d/lanzhou/caroad8",
            "east"  :  "/d/changan/ca34",
        ]));

        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
  	     "/d/city/npc/xunbu" : 1,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        setup();
        replace_program(ROOM);
}



