inherit  ROOM;
void  create  ()
{
        set  ("short",  "������������");
        set  ("long",  @LONG
�����ǳ����ǵ������š�����͵��˳��У�Զ����ɽ�˺�������
���˳�������������һ����·ͨ��Զ������������һЩִ�ڵı�ʿ��
ʱ����������̫ƽ����һ�ɱ�������Ӣ�˲���������Ķ���������
ʿ��
LONG);
        set("exits",  ([
            "up"  :  __DIR__"ca29",
            "east"  :  __DIR__"ca18",
]));
        set("objects",  ([
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        setup();
        replace_program(ROOM);
}

