// Room: /d/sandboy/shandao 
#include <ansi.h>
inherit ROOM; 
 
void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG
����һ���ľ���ɽ����̫��ů�������ͷ�ϣ�Ϫˮ�����õ��ڽű������� 
С���������ŷɹ���Զ�����֣����ߵ�����һ��ѿ��õ�ë��һֻ�� 
��«�ͷ����Ƕ�ë��ߣ���һ���չޡ�һ�������Լ��������Ų����Ĵֲ� 
���ѷ���һ��������һƬ���֣��������ǵĿ������� 
LONG);

  set("objects", ([ /* sizeof() == 4 */
  "/d/hainan/npc/man1" : 2,
  __DIR__"obj/taoguan.c" : 1,
  __DIR__"obj/ciwan.c" : 1,
  "/d/hainan/npc/man2" : 2,
]));
set("outdoors","/d/jiangnan");
  set("item_desc", ([ /* sizeof() == 3 */
  "����" : "һƬ�����֣���Լ�кü�ʮ�á� 
",
  "����" : "�����ë��ܶ࣬һɽһɽ�ģ�ɢ����Ũ�������㡣 
",
  "Ϫˮ" : "ɽȪ�Ӹߴ����£��γɵ�СϪ���� 
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhulin",
  "east" : __DIR__"shandao",
]));

  setup();
}
void init()
{
 add_action("do_get","get");
 add_action("do_kan","kan");
}
int do_get(string arg)
{
  object ob,ob1;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   if (arg=="all"||arg=="hulu"||arg=="cloth"||arg=="taoguan"||arg=="ciwan")
    { 
        message_vision(HIY+"ͻȻ�ӵ��ϵ���һ�����ң���$N����������.\n"+NOR,ob);
        ob->move(__DIR__"zhushao");

         ob1=present("cuizhu",this_object());
         if (!ob1)
         {
           ob1=new(__DIR__"obj/cuizhu");
                    ob1->move(this_object());
                 }
     ob1->init();
     return 1;
    }
  return notify_fail("");
}
int do_kan(string arg)
{
   object ob,ob1,ob2,*inv,ob3;
   int i;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   if (arg=="����"||arg=="cuizhu")
           {
               ob1=present("cuizhu",this_object());
               if (!ob1) return notify_fail("������Ҫ���Ĵ���?\n");
               ob3=ob->query_temp("weapon");
               if(!ob3||(ob3->query("name")!="����")) 
                                 return notify_fail("��û��װ������!\n");
               message("vision","ֻ������һ��,"+HIG+"����"+NOR+"��"+ob->query("name")+"������!\n",this_object());
               destruct(ob1);
            new(__DIR__"obj/cuizhu2")->move(this_object());
                     ob2=load_object(__DIR__"zhushao");
               	inv=all_inventory(ob2);
        	if(sizeof(inv))
                {   
                        tell_room(__DIR__"zhushao",HIR+"ֻ������һ�������ӱ������ˣ��������ȥ!\n"+NOR);
                        tell_room(__DIR__"shandao2",HIR+"���˴������ϵ�������!\n"+NOR);
                   	for(i=0;i<sizeof(inv);i++)	{
                                        inv[i]->move(this_object());
                                               }
                              }
                return 1;
             }
    return notify_fail("��Ҫ��ʲô?\n");
}



