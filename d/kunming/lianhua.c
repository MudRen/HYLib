// /d/kunming/lianhua
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "������" NOR);
        set("long", @LONG
���������壬ʯ�ַ�⾡���۵ף��ۼ����߿���һ����(zi),����
��һСͤ(ting)������Ͽ���һСʫ(shi)�����¹�����ֻ��һ̶��ˮ
����(tang)���澰�����������������·ת���쾳�쿪��Ϥ�Ĺ۲죬
��������ʹ���Ķ���ۣ��ֶ������ӡ�

LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                
                "southdown"  :__DIR__"shilin2",        
               
        ]));

        set("item_desc", ([
                     "zi" :  "  ~~~~~~~~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  ��  ~ \n" +
                             "  ~      ~ \n" +
                             "  ~  ��  ~ \n" +
                             "  ~      ~ \n" +       
                             "  ~  ��  ~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  һ  ~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  ��  ~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  ��  ~ \n" +
                             "  ~      ~ \n" +   
                             "  ~~~~~~~~ \n\n\n" ,
                     "shi" : " �� �� ֱ �� �� �� ����\n\n" +
                             " һ �� �� �� �� �� �壻\n\n" +
                             " �� �� � �� �� �� ˮ��\n\n" +
                             " �� �� ˫ �� �� �� �ա�\n\n\n",

                     "tang" : "һ������׵�ˮ̶����Ի�����ء�������һʯ����Ի���Խ�ʯ��\n",
                     "ting" : "һ��Сͤ�ӣ���Ϊ������ͤ������һ�������ϣ����ܶ����ͱڣ��޷�\n"+
                              "�ʵǣ����Ҫ��ȥ�Ļ���ֻ�д���������!\n",
                  ]));
        setup();
        }

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me ;
	int  i_dodge;
	me=this_player();
	i_dodge=(int)me->query_skill("dodge");
        
	if (!arg || arg=="" ) return 0;
	if (arg!="down" && arg!="ting") return 0;
        switch (arg){
               case "down" :
			 message("vision",me->name() + "������ȥ��\n",environment(me), ({me}) );
                     	if (i_dodge < 30)  {me->move(__DIR__"shijianchi");
                                         message("vision",
			                "ֻž��һ������һ���˴��������������ˤ�˸��Ļ����ء�\n",
			                 environment(me), ({me}) );
                                         me->unconcious();
                                       } 
                     else {me->move(__DIR__"shijianchi");
			   message("vision",
		        	"ֻ����Ӱһ��"+me->name() + "����������������\n",
			    environment(me), ({me}) );
	                   message("vinson","����������һ�������ȵ������Խ����м䡣\n" , me);
                          }
                     break; 
               case "ting" :
                     if (i_dodge < 60)  return notify_fail("����Ṧ������������ȥ��\n");
                     else { message("vision",
			me->name() + "������ͤԾ�˹�ȥ��\n",
			environment(me), ({me}) );
			 me->move(__DIR__"wfting");
                            message("vinson","������һ����ֻ��������ƮƮ�ķ��˳�ȥ��\n" +
                                             "����һ��������������ͤ�ϡ� \n", me);
                          }
                     break; 
                    }
    return 1;
	}