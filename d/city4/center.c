//changan  city

inherit  ROOM;

void  create  ()
{
	set  ("short",  "ʮ�ֽ�ͷ");
	set  ("long",  @LONG
������ǳ����ǵ����ģ���������������ֽ����ڴˡ��㳡����һ
��Ρ��ߴ����¥������ǰ�����б��Ĺ�¥ң���Ӧ��������Щ���ơ�
ÿ���峿�����������������ŵ����������򳤰��ǵĴ��С�·��
��ˮ�����������˳����ϡ�
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

        set("exits",  ([  //sizeof()  ==  4
            //"north" :  __DIR__"club",
            //"south" :  __DIR__"bank",
		"north" :  __DIR__"northroad2",
		"south" :  __DIR__"southroad2",
		"east"  :  __DIR__"eastroad2",
            //"west"  :  __DIR__"westgate",
            "west"  :  "/d/changan/ca34",
            //"east"  :  __DIR__"eastgate",
        ]));
        set("objects",  ([  //sizeof()  ==  1
             __DIR__"npc/petowner"  :  1,
"/clone/master/master"+(random(24)+1): 1,
        ]));
        set("outdoors",  "changan");
        setup();
	replace_program(ROOM);
}

