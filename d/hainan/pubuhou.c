// Room: /d/hainan/pubuhou
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "�ٲ���");
  set ("long", @LONG
����һ��ͦ���ɽ��,�벻���ٲ����������ô��ɽ��,�������˾��� 
���ж���.���������ˮ��̫��,����������ַ���������Ҳ������.����� 
ʯ���������ִ������.˩��һ�����ӻҰ׵���������. 
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/luhai.c" : 1,
  __DIR__"obj/tielian.c" : 1,
]));
  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "����" : "һ���ִ������,�Գ�����Ĺ�.�������Ƿ�������. 
",
]));
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"pubu",
]));

  setup();
}
void init()
{
   add_action("do_kan","kan");
   add_action("do_kan","zhan");
   add_action("do_kan","��");
   add_action("do_kan","ն");
}
int do_kan(string str)
{ object ob,me,ob1,ob2,ob3;
  ob=present("lu hai");
  ob1=present("tielian");
  me=this_player();
  if (str!="������"&&str!="tielian") return notify_fail("��Ҫ��ʲô?\n");
  if (!ob1) return notify_fail("�����Щ,������Ҫ��������?\n");
 if( !(ob2=me->query_temp("weapon"))||(string)ob2->query("id")!="hanyue blade")
      return notify_fail("����������ֻ�к���ն����ն��!\n");
message_vision("$N���һ��:��!... ...һ����$n����!\n",me,ob1);
  if (me->query("gender")=="Ů��")
return notify_fail("����������������,�ͱ���������������ס,�������㴿�������й�!\n");
 message_vision("ֻ��...��...��һ��,����Ӧ������,��$N��Ϊ����!\n",me);
destruct(ob1);
ob3=new(__DIR__"obj/duantielian");
ob3->move(environment(me));
if (ob)
   { 
     ob->set("title",YEL"����һ��"NOR);
if (find_object("/d/hainan/obj/biyu")||ob->query("no_biyu")==1)
   message_vision("$N������Ц:�����������ĥ����,�����ҹ����������ϵ�.\n",ob);
  else {
     message_vision("$N����Ծ��,������Ц:����... ...�ϵ�����������!
��!��!��!���������͸���,�ĵ��Ϸ��һ��л��!
$N�ݸ�$nһ��������ѩ��!\n",ob,me);
     clone_object("/d/hainan/obj/biyu")->move(me);
ob->set("no_biyu",1);
   }
     }
return 1;
}   
