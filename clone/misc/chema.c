// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
          add_action ("do_fly","chema");
}

void create()
{
	set_name(YEL"���ֳ���Ʊ"NOR, ({"chema piao", "piao"}));
        set("unit", "��");
set("long", YEL"Ϊ�˷����ҡ���ͨ����(chema)����\n
 Ŀǰ�����ȥ�ĵط�������:
����(tam)   ����(dl)   Ȫ��(qz) ����(gc)  ����(tg)   ����ׯ(gyz)
����(xy)    �书��(wg) ����(ca) ����(laz)  ����(gw)   ������(jdz)
���ǳ�(yd)  ������(yl) ��ɽ(fs) ����(yz)  ��ƽ(yp)   ����(jl)
�ɶ���(cd)  ������(wx) ����(lz) ����(jinl)���ݳ�(sz) ���ݳ�(hz)
���ݳ�(fz)  ����(cz)   ʢ��(yj) ����(km)  ����(jz)   ����(ly)
����(yy)    ����(yx)   
\n"NOR      
);

             set("value", 800);
             set("material", "steel");
        setup();
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("�㾫�񲻹���ʢ��û����������\n");
if( me->query_temp("pending/team"))
               return notify_fail("�����ͱ�������أ�\n");				

if( !environment(me)->query("no_fight") && me->query("combat_exp") > 800000)
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
"$N���˸���򣬲������е����ֳ���Ʊ����������ǣ��������\n"+
"$N�����������һ������ඡ���ֻ�����ɱ���ȥ������\n\n"NOR, me);
}
           if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="tam") pla = "/d/beijing/tian_anm";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
else if(arg=="yd") pla = "/d/huanghe/yongdeng";
	else if(arg=="yl") pla = "/d/xingxiu/majiu";
else if(arg=="fs") pla = "/d/foshan/northgate";		
else if(arg=="yz") pla = "/d/city/guangchang";			
else if(arg=="yp") pla = "/d/yanping/majiu";			
else if(arg=="jl") pla = "/d/jiangling/beimen";				
else if(arg=="cd") pla = "/d/chengdu/majiu";					
else if(arg=="wx") pla = "/d/wuxi/majiu";						
else if(arg=="lz") pla = "/d/lingzhou/majiu";						
else if(arg=="jinl") pla = "/d/jinling/nanmen";						
else if(arg=="sz") pla = "/d/suzhou/majiu";						
else if(arg=="hz") pla = "/d/hangzhou/majiu";							
else if(arg=="fz") pla = "/d/fuzhou/majiu";							
else if(arg=="dl") pla = "/d/dali/majiu";								
else if(arg=="yj") pla = "/d/yanjing/street4";								
else if(arg=="km") pla = "/d/kunming/dongmen";								
else if(arg=="jz") pla = "/d/jingzhou/majiu";								
else if(arg=="ly") pla = "/d/luoyang/center";									
else if(arg=="yy") pla = "/d/yueyang/guangchang";									
else if(arg=="yx") pla = "/d/yixing/yixing";									
else if(arg=="cz") pla = "/d/cangzhou/beimen";									
else if(arg=="tg") pla = "/d/tanggu/beimen";									
else if(arg=="wg") pla = "/d/quanzhen/guchang";									
else if(arg=="ca") pla = "/d/city4/eastgate";									
else if(arg=="laz") pla = "/d/lanzhou/ximen";									
else if(arg=="gw") pla = "/d/guanwai/nancheng";									
else if(arg=="jdz") pla = "/d/jindezheng/center";		
               else {
               message_vision(HIR
"�����˰��죬�ŷ���$NҪȥ�ĵط�����û�Ǹ�վ��\n���$N���������������ˤ�ñ������ף�\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(YEL"\n���ˣ������ȵ�ͣ�����£�$N�����������Գ�����˻��֡�\n"NOR,me);
   me->add("jing",-30);
}
	destruct(this_object());
     return 1;
}