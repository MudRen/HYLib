// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
���Ǵ�˵�����صİ���ɽ��ԶԶ��ȥ��������ɳ�ѻ��γɵ�ɽ�����
һֻ���յļ�����һ��ɽ�����������ǰ��ɽ�ź�һ��С·ͨ��һ��ɽ��
�ϵ�ɽׯ�������ǡ�������ŷ�������լ��һ���˴���ȥ�������ˡ�
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"shamo4",
            "west" : __DIR__"btshan1",
        ]));

        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="west" ) {
        if (objectp(present("snake", environment(me))))
                return notify_fail("���󲻹��������ɽ?\n");

        if (objectp(present("ouyang ke", environment(me))))
                return notify_fail(
"ŷ���˶������ȣ�һ���ֵ�ס�����ȥ·���常���������������������\n");
        
       
        me->move(__DIR__"btshan1");
        write("ŷ���湭���ȭ�����ڷ������������Ľ�����˫ĿԲ����\n");
        write("��Ȼ��ŷ����˫��һ�ţ�����ƽ�����������\n");
        write("��һ���������ǰ�أ���о�������������������һ����\n");
        write("��ƽ�ɳ��˰���ɽׯ��\n");
        me->move(__DIR__"btshan");
        me->set("qi",10);
        me->unconcious();
        return 1;
   }
   return ::valid_leave(me, dir);
}

