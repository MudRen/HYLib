 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������Ϊ�¹��������󲿷��������粨�ĸɺԺ��ף�
��Ŀ�������׾�Ө���ΰͣ����������������⣬���ƺ�ҹ����
���¹⣬������������
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tulufan",
  "westdown" : __DIR__"pubu",
]));
        set("objects", ([
        __DIR__"npc/saltboss" : 1,
                        ]) );
        set("item_desc", ([
           "�ΰ�": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
           "yanba": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
           "salt rock": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
        ]));
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1070);
        set("coor/y",2020);
        set("coor/z",10);
        setup();
} 
void dig_notify()
{
     object me, salt;
     if(query("already")) return 0;
     me = this_player();
     message_vision("�ϣ�����һ�����ٿ����ϵ��ΰ��Ա�$N����һС�顣\n", me);
     salt = present("salt rock", this_object());
     if(!objectp(salt)) {
        salt = new(__DIR__"obj/salt");
        salt->move(this_object());
     }
        set("already",1); 
}    
