inherit  ROOM;
void  create  ()
{
        set  ("short",  "�ַ���¥");
        set  ("long",  @LONG 
�ַ�¥���Եø������֣���������������������������������
�ӣ���ǩ����Ǯ�����̵����������������ӣ������Ƕĵ������ء�
LONG
); 
        set("exits",  ([
                "up"  :  __DIR__"shishe",
                 "west"  : "/d/changan/qinhuang/duroom",
                "down"  :  __DIR__"ca15",
        ]));
        set("objects",  ([
//               __DIR__"npc/libai"  :  1,
                 __DIR__"obj/tables"  :  3,
        ]));
        set("no_clean_up",  0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && (userp(me)))
                return notify_fail("�ĳ�����װ���У����ǲ�Ҫȥ�˰ɣ���\n");
        return 1;
}

