// caoyuan.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ��Ե");
        set("long", @LONG
�����Ǵ��ԭ��ɳĮ����֮�أ������ϡ���ܣ��������������ȥ��
�����м�������̤������ӡ�����������ﳣ�����̶����������Ϸ�������
Щ���̡�
LONG);
        set("exits", ([
           "southwest" : __DIR__"caoyuan1",
            "northwest" : __DIR__"caoyuan2",
            "northup" : __DIR__"caoyuan3",
            "north" : __DIR__"dadao1",
            "south" : __DIR__"caoyuan1",
            "east":__DIR__"ximen",
        ]));
        

        
        set("outdoors", "dingxiang");
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/steps",1);
       if (dir == "south") me->add_temp("mark/steps",-1); 
        
       if (dir=="north"&&me->query_temp("mark/steps")<4){
       	  me->add("water",-10-random(10));
       	  if(me->query("water")<=0)
       	   me->set("water",0);
       	  return notify_fail("��ǳ��ڿʣ������߲���·�ˣ�\n");
       }
       if (dir=="south"&&me->query_temp("mark/steps")>-4){
       	  me->add("water",-10-random(10));
       	  if(me->query("water")<=0)
       	   me->set("water",0);
       	  return notify_fail("��ǳ��ڿʣ������߲���·�ˣ�\n");
       }
        me->delete_temp("mark/steps");
        return ::valid_leave(me, dir);
}
