 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ǳ�͢���裬��������ľ��׶�������������״��������������һ�ž�
��ľ���������и�С��Ͱ��������ż�����֪����ӡ����ǩ��ľ�����̫ʦ��������
ѩ��Ƥ���κ������Ϻ�������ͼ����������ң�
                                �������

LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"street5",
        "south" : __DIR__"shufang",
        "west" : __DIR__"xiangfang",
    ]));
    set("objects", ([
        __DIR__"npc/yayi0" : 1,
        __DIR__"npc/yayi1" : 2,
        __DIR__"npc/yayi" : 2,
        __DIR__"npc/yayi2" : 2,
    ]) );
        set("coor/x",30);
        set("coor/y",1880);
        set("coor/z",0);
        setup(); 
} 

valid_leave(object me,string dir)
{
        object xing;
        
        if((dir =="south" || dir == "west") && me->query("class")!="official"
                &&xing=present("xing rui",this_object()))
                return notify_fail("�������ȵ����������ô���Ҫ�صأ�����\n");
        return 1;
}  
