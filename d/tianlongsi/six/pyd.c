//���Ƹ�
//cool@SJ,990605

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"���ƶ�"NOR);
         set("long",
"ԭ�������Ƹ�����һ��Сɽ����һ�������ž�������Ϣ�Ĺر��ˣ�����һ����Ⱦ���ǳ��ɾ���
�������Զ������ƺ��п�ǳ���ı�ʯ������ǽ�����˹�������ͼ��(tupu)�����Ϸ��ż������ţ�
��������˸��ط�����������\n"
);
         
         set("item_desc", ([
             "tupu" : "ͼ���ϻ��ž���Ѩλͼ���ֱ�����·�񽣵��������š�\n",
]));

set("exits", ([
	       "out" : __DIR__"lsy",
        ]));
      
//         create_door("out", "ʯ��", "enter", DOOR_CLOSED);
setup();
}

int init()
{
        add_action("do_kan","kan");  
        add_action("do_kan","du");
        add_action("do_kan","yandu");
        add_action("do_kan","lingwu");
        add_action("do_kan","study");
}

int do_kan(string arg)
{         object me;
        me = this_player();
        if ( !living(this_player()) || arg != "tupu" )
                 return 0;
//        if (me->query("family/master_name")!="���ٴ�ʦ" )  
//        return 0;
        if ( (int)me->query_skill("literate", 1) < 1)
                 return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�����������񽣰ɡ�\n");
	if ( (int)me->query_skill("yiyang-zhi", 1) < 160 )
                 return notify_fail("ƾ�����ڵ�һ��ָ��Ϊ���޷�������������ô������书��\n");
        if ((int)me->query_skill("six-finger", 1) > 200)
                 return notify_fail("��˼���˺ܾã��ƺ���Щ�ط������޷����ף�\n");
        if ( (int)me->query("max_neili")<2500 && (int)me->query_skill("six-finger",1)>=30)
                 return notify_fail("��ֻ�������ƺ������������޷�����������\n");
        if ( (int)me->query("max_neili")<3000 && (int)me->query_skill("six-finger",1)>=60)
                 return notify_fail("��ֻ�������ƺ������������޷�����������\n");
        if ( (int)me->query("max_neili")<3200 && (int)me->query_skill("six-finger",1)>=90)
                  return notify_fail("��ֻ�������ƺ������������޷�����������\n");
        if ( (int)me->query("max_neili")<3500 && (int)me->query_skill("six-finger",1)>=120)
                  return notify_fail("��ֻ�������ƺ������������޷�����������\n");
        if ( (int)me->query("max_neili")<4500 && (int)me->query_skill("six-finger",1)>=150)
                  return notify_fail("��ֻ�������ƺ������������޷�����������\n");
         
        if ( (int)me->query("jing")<100) {
                 write("��̫���ˣ��Ѿ�û�о����������ˣ�\n");              
                 return 1;
        }
	me->receive_damage("jing", random(me->query_skill("six-finger",1))/2+10);
        message_vision("$N������ϸ�Ŀ���ͼ�ס�\n", me);
        if (me->query_skill("six-finger",1)<50)  
        write("����ϸ��ĥ�����ף���������һ����ᡣ\n");
        if (me->query_skill("six-finger",1)>=70 && me->query_skill("six-finger",1)<60 )  
        write("����ϸ��ĥ�س彣�ף���������һ����ᡣ\n");
        if (me->query_skill("six-finger",1)>=90 && me->query_skill("six-finger",1)<90 )  
        write("����ϸ��ĥ�������ף���������һ����ᡣ\n");
        if (me->query_skill("six-finger",1)>=120 && me->query_skill("six-finger",1)<120 )  
        write("����ϸ��ĥ�г彣�ף���������һ����ᡣ\n");
        if (me->query_skill("six-finger",1)>=150 && me->query_skill("six-finger",1)<150 )  
        write("����ϸ��ĥ�ٳ彣�ף���������һ����ᡣ\n");
        if (me->query_skill("six-finger",1)>=180)  
        write("����ϸ��ĥ���̽��ף���������һ����ᡣ\n");
        me->improve_skill("six-finger", me->query_skill("finger")/10);
         return 1;
}
