inherit  ROOM;

void  create  ()
{
        set  ("short",  "�����Ƕ�����");
        set  ("long",  @LONG
�����ǳ����ǵĶ����š�����͵��˳��У�Զ����ɽ�˺�������
���˳�������������һ����·ͨ��Զ������������һЩִ�ڵı�ʿ��
ʱ����������̫ƽ����һ�ɱ�������Ӣ�˲���������Ķ���������
ʿ��
LONG);
        set("exits",  ([
                "west"  :  __DIR__"ca17",
                "southwest"  :  __DIR__"shuyuan",
              "up":__DIR__"ca30",
                "east"  :  __DIR__"ca32",
        ]));
        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  3,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        setup();
        replace_program(ROOM);
}

