// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
        add_action("do_eat", "ci");
        add_action("do_eat", "he");
        add_action("do_sleep", "xiuxi");
          add_action ("do_fly","chen");
}

void create()
{
	set_name(YEL"���ֱ���"NOR, ({"newbie beg", "beg"}));
        set("unit", "ֻ");
	set("long", "�����濴��ȥ����Զ�Բ���ĸ����������ֳ��ֺȲ���Ϣ(he,ci,xiuxi)��\n");
set("long", YEL"����ר�ã������濴��ȥ����Զ�Բ���ĸ�����\n
            ������ֳ��ֺȲ���Ϣ����ѳ˳�(he,ci,xiuxi,chen)����\n
           *@*@*@*@*@*@*@*@*@*���Դ����(chen)�����µط���*@*@*@*@*@*@*@*@*@*

              ��������������������������������������������������������
              ���� ����(tam)        ����(dl)            Ȫ��(qz)  ����
              ���� ����(shl)        ��ɽ(hs)            ����(lj)  ����
              ���� �䵱(wd)         ����(mj)            ����(gc)  ����
              ���� ����(xx)         ѩɽ(xs)            ��ü(em)  ����
              ���� ȫ��(quz)        ����ɽ(bt)          ��Ĺ(gm)  ����
              ���� ����(sz)         ����ׯ(gyz)         ����(xy)  ����
              ���� ����(ca)         �ɶ�(cd)            ����(laz) ����
              ���� ����(jz)         ʢ��(yj)            ���(wg)  ����
              ���� ����(km)         ����(hz)            ����(lz)  ����
              ��������������������������������������������������������\n"NOR      
);
	set("no_get",1);
	set("no_drop",1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
             set("value", 0);
             set("material", "steel");
             set("no_drop", "�������������뿪�㡣\n");
        setup();
}

int do_eat(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if (me->query("age") > 17)
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");
if (me->query("str") > 40)
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");
if (me->query("dex") > 40)
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");

if (me->is_busy())
return notify_fail("��Ҫ��ʲô��\n");
if (me->is_fighting())
return notify_fail("��Ҫ��ʲô��\n");
if ((int)me->query("combat_exp") > 600000 )
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");

if (me->query("food")*1.5 > me->max_food_capacity())
return notify_fail("�����ڲ�����!\n");
if (me->query("water")*1.5 > me->max_water_capacity())
return notify_fail("�����ڲ�����!\n");
message_vision(YEL "$N�ó�������Դ����һ��!!\n" NOR,me);
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
me->start_busy(10);
}
int do_sleep(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if (me->query("age") > 17)
return notify_fail("ֻ�����ֲ�����!\n");
if (me->query("str") > 40)
return notify_fail("ֻ�����ֲ�����!\n");
if (me->query("dex") > 40)
return notify_fail("ֻ�����ֲ�����!\n");

if (me->is_busy())
return notify_fail("��Ҫ��ʲô��\n");
if (me->is_fighting())
return notify_fail("��Ҫ��ʲô��\n");
if ((int)me->query("combat_exp") > 600000 )
return notify_fail("ֻ�����ֲ�����!\n");

if (me->query("qi") > me->query("max_qi")
&& me->query("jing") > me->query("max_jing")
)
return notify_fail("�����ڲ�����!\n");
message_vision(YEL "$N�ó����ֱ������ڵ�����Ϣһ��!!\n" NOR,me);
if (me->query("qi") < me->query("max_qi"))
me->add("qi",me->query("max_qi")/5);
if (me->query("jing") < me->query("max_jing"))
me->add("jing",me->query("max_jing")/5);
me->start_busy(12);
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("�㾫�񲻹���ʢ��û����������\n");
if( me->query_temp("pending/team"))
               return notify_fail("�����ͱ�������أ�\n");				

if( !environment(me)->query("no_fight") && me->query("combat_exp") > 500000)
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if (me->query("age") > 17)
{
  message_vision("ֻ��С��18�꣬�����������!!!\n"
                 ,me);
      	return 1;
}
    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");

          if (!arg)
              return notify_fail("����ȥ���\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("��ôΣ�գ��ǻ���ʱ��ȥ����?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("���뿪�����������ж���\n");
          if( environment(me)->query("light_up"))
               return notify_fail("�ĳ��ﲻ������!!\n");


          else {
          message_vision(HIY
"$N���˸���򣬲���ʾ�����е����ֳ���Ʊ�����ǣ��������\n"+
"$N�����������һ������ඡ���ֻ�����ɱ���ȥ������\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/city2/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
     else if(arg=="ca") pla = "/d/changan/ca";
     else if(arg=="cd") pla = "/d/city3/guangchang";
     else if(arg=="laz") pla = "/d/lanzhou/guangchang";
     else if(arg=="jz") pla = "/d/jingzhou/guangchang";
     else if(arg=="km") pla = "/d/kunming/jinrilou";
     else if(arg=="yj") pla = "/d/yanjing/street";               
     else if(arg=="wg") pla = "/d/wuguan/guanmen";
     else if(arg=="hz") pla = "/d/hangzhou/kedian";
     else if(arg=="lz") pla = "/d/lingzhou/center";
               else {
               message_vision(HIR
"�����˰��죬�ŷ���$NҪȥ�ĵط�����û�Ǹ�վ��\n���$N���������������ˤ�ñ������ף�\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n���ˣ������ȵ�ͣ�����£�$N�����������Գ�����˻��֡�\n"NOR,me);
if( me->query("age") <= 16 )
           me->add("jing",-10);
 else   me->add("jing",-30);
}
     return 1;
}