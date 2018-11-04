// Room: /d/huashan/sgyhole.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������������������ɱ��ĵط�����ǽ���в��ٺ��ǣ�
����������ﾲ������ɱ��.
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "out"     : __DIR__"pingtai",
        ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo()
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("shayi", 1);
   if (c_skill <50)
   {
      message_vision("$N��ɱ��̫���ˣ��޷���ᵽ�����ɱ�⡣\n",ob);
      return 1; 
   }
   c_exp=ob->query("combat_exp");

   if ((c_skill*c_skill*c_skill/10)> c_exp)
   {
      message_vision("$N��ʵս���鲻�㣬�����˰���û���κ�����\n",ob);
      return 1; 
   }
   if (ob->query("jing")<50)
   {
      message_vision("$N̫���ˣ�������ȥֻ��Ҫ�ε���\n",ob);
      return 1; 
   }
   if (c_skill>301)
   {
      message_vision("$N���þ����Ѷ��Լ�����ʲô�����ˡ�\n",ob);
      return 1; 
   }

   message_vision("$N��ϥ����,Ƭ�̹����ɱ������Щ����\n",ob);
   ob->improve_skill("shayi", random(2*ob->query("int")));
   ob->add("jing",-ob->query("eff_jing")/20);
   return 1;
}

