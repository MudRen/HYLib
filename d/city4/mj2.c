/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/city/club3
inherit  ROOM;

void  create  ()
{
    set  ("short",  "�齫��");
    set  ("long",  @LONG
����һ��������Ĵ������������м���һ��Բ�ε����ӡ���
���ϣ��������з���һ���齫̨���м�����������������ơ�
LONG);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
        "north":  __DIR__"mj1",
    ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"mj/south"  :  1,
                __DIR__"mj/west"  :  1,
                __DIR__"mj/east"  :  1,
                __DIR__"mj/1mj"  :  1,
       ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
