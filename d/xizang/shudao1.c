 inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�Թ����·���У�һ��ʫ�����ʫԻ������Ϸ��Σ�����գ����֮����������
�죡������ɽӳ��ˮ��һ·�������ۣ�������̲������ʯջȮ������Գ�񰧺Ź�
ľ���죬���;����������̡���˰��������ֳ�����·Ϊ��������������С�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"hutiao",
  "northeast" : __DIR__"shudao2",
]));
        set("outdoors", "guanwai");
        set("coor/x",-810);
        set("coor/y",-660);
        set("coor/z",0);
        set("objects", ([
                __DIR__"obj/tianti" : 1,
        ]));
        setup();
} 
int valid_leave(object me, string dir)
{
        
        int max_jing;
        if (dir == "northeast")
        {
        if(random(5))
                {
                        max_jing = me->query("max_jing");
                        max_jing = me->query("max_jing"); 
                        if (me->query("jing") <= max_jing /5)
                        {
                                  return notify_fail("������̫���ˣ���������Ϣһ�°ɡ�\n");
                        }
                        me->add("jing",-(max_jing*(10+random(10))/100));
                        me->add("qi",-(max_jing*(10+random(10))/100));
                        me->move(this_object());
                   tell_object(me,"���������ѵ�ɽ��ʰ�����ϡ�\n");
                        if(me->query("sen") <= max_jing/2)
                        {
                                tell_object(me,"�㺹�����꣬ÿһ�����Ǽ��������Բ�Ը������ҧ��ǰ�С�\n",);
                        }else
                        {
                                tell_object(me,"������ȥ�����������ͣ������޾�������ȴ�������ѡ�\n");
                        }
                        return notify_fail("");
                }
        }
        return 1;
}    
