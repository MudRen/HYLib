//Cracked by Roath
#include <ansi.h>
#include <command.h>
inherit ITEM;
void create()
{
        set_name(YEL "ÇúÆ×" NOR, ({ "qu pu", "pu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "²á");
                set("long", "
Ò»²áñÑ¶¤¾«ÃÀµÄÇúÆ×£¬Äã¿ÉÒÔ³ª(chang)ÀïÃæµÄÇú×Ó£º

¡¡¡¶ÏãÚ£¡¤ÃúÎÄ¡·(xiangzhong)
¡¡¡¶¶´ÏÉ¸è¡·(dongxian_ge)
¡¡¡¶ÂõÚéÌÁ¡¤ÑãÇğ´Ê¡·(maipo_tang)
¡¡¡¶²¨Ë¹Ğ¡Çú¡·(bosi_xiaoqu)
¡¡¡¶Ğ¦°Á½­ºş¡·(xiaoao_jianghu)
¡¡¡¶É½ÆÂÑò¡·(shanpo_yang)
¡¡¡¶µûÁµ»¨¡·(dielian_hua)
¡¡¡¶²ÉÉ£×Ó¡·(caisang_zi)
¡¡¡¶ÎŞË×Äî¡·(wusu_nian)   
¡¡¡¶¶´ÏÉ¸è¡·(dongxian_ge)
¡¡¡¶²ÉÉ£×Ó¡·(caisang_zi)
  ¡¶ÈıÌ¨¡·(san_tai)
  ¡¶Óù½ÖĞĞ¡·(yujie_xing)
  ¡¶×í´¹±Ş¡·(zuichui_bian)
  ¡¶Ë®µ÷¸èÍ·¡·(shuidiao_getou)
  ¡¶Ô²Ô²Çú¡·(yuanyuan_qu)
  ¡¶Íûº£³±¡·(wanghai_chao)
  ¡¶ÎÊÊÀ¼ä  ÇéÎªºÎÎï¡·(wenshi_jian)
  ¡¶µûÁµ»¨¡·(dielian_hua)
  ¡¶ÒûÂí³¤³Ç¿ßĞĞ¡·(yinma_changcheng)
  ¡¶´º½­»¨ÔÂÒ¹¡·(chunjiang_huayueye)
  ¡¶½«½ø¾Æ¡·(jiangjin_jiu)
  ¡¶Ğ¦°Á½­ºş¡·(xiaoao_jianghu)
  ¡¶ÓİÃÀÈË¡·(yu_meiren)
  ¡¶°×Ñ©¸èËÍÎäÅĞ¹Ù»Ø¾©¡·(baixue_ge)
  
ÄãÈç¹û¾õµÃ³ªµÃ²»ºÃ£¬¿ÉÒÔÍ£(ting)ÏÂ£¬ÔÙ»ØÈ¥Á·Á·¡£
\n");
                set("value", 0);
                set("material", "silk");
             }
        setup();
}

void init()
{
        add_action("do_sing", "chang");
        add_action("do_halt", "ting");
}
#include "sing.c";

int do_halt()
{
        if (find_call_out("sing_stage") < 0) return 0;
        message_vision(HIR"\n$N·¢ÏÖ´ó¼ÒÒ»Á³Í´¿àµÄ±íÇé£¬ŞÏŞÎµØ¿ÈËÔÁËÁ½Éù£¬Í£ÏÂÁËÔëÒô¡£\n"NOR, this_player());
        remove_call_out("sing_stage");
        return 1;
}

int do_sing(string arg)
{
       object me, ob,ob1; 
       int i = sizeof(qupu);
       int stage;
        string st1,st2,song;
   mapping myfam, vtfam;
       stage = 0;
       me = this_player();
       ob = this_object();
       if (find_call_out("sing_stage") >= 0) return notify_fail("ÄãÄÜÍ¬Ê±³ªÁ½Ê×Çú×ÓÂğ£¿\n");
        if (!arg || arg=="") return notify_fail ("ÄãÏëÎªË­³ªÊ²Ã´°¡£¿\n");

        if (sscanf( arg,"%s %s",st1,st2)!=2 )
           return notify_fail ("chang <Ä³ÈË> <ÇúÃû>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("ÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n");

if (environment(me)->query("sleep_room"))
                return notify_fail("ÎÔÊÒÀï³ª¸è£¬»áÓ°Ïì±ğÈËĞİÏ¢¡£\n");

if( environment(me)->query("no_beg") &&
      environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n²»ÒªÓ°Ïì±ğÈË£¬»¹ÊÇÕÒÒ»¸ö±ğµÄµØ·½°É¡£\n"NOR);

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "åĞÒ£ÅÉ"))
          return notify_fail("Ö»ÓĞåĞÒ£ÅÉµÜ×Ó²ÅÓĞÕâ¸ö×Ê¸ñ£¡\n");
if( !ob1->is_character()
|| !living(ob1))
return notify_fail("Ö»ÄÜ¶ÔÕı³£ÈËµ¯ÇÙ³ª¸è¡£\n");

    if (me->query("gender")=="ÄĞĞÔ" && ob1->query("gender") !="Å®ĞÔ" ) 
          return notify_fail("ÄãÒ»¸ö´óÄĞÈË£¬ÎªÒ»¸ö´óÄĞÈËµ¯ÇÙ³ª¸è?».\n");
    if (me->query("gender")=="Å®ĞÔ" && ob1->query("gender") !="ÄĞĞÔ" ) 
          return notify_fail("ÄãÒ»¸ö´ó¹ÃÄï£¬¸ø±ğµÄ¹ÃÄïµ¯ÇÙ³ª¸è?».\n");

song=st2;
me->set_temp("singn",st1);
       if(!arg) return notify_fail("ÄãÏë³ªÊ²Ã´£¿\n");
        while (i--) if (song == qupu[i]["name"]) break;
        if (i<0) return notify_fail("ÇúÆ×Àï»¹Ã»ÓĞÄãÏë³ªµÄÇú×Ó¡£\n");
        if(me->is_busy())
           return notify_fail("ÄãÕıÃ¦×ÅÄØ¡£\n");
        message_vision(HIG"$N¶Ô$nµãÁËµãÍ·¡£\n\n"NOR,me, ob1);
        message_vision(HIG"$NÄÃÆğ¹ÅÇÙ·ÅÔÚ»³ÖĞÂıÂıµÄ±ßµ¯±ß³ªÁËÆğÀ´£¬ÇÙÉùÇå¶ø²»µ­£¬Ïì¶ø²»Ë×£¬ÁîÈË²»¾õÌÕ×íÆäÖĞ¡£\n\n"NOR,me, ob);
if (me->query_temp("singsong"))
{
if (qupu[i]["name"]!=me->query_temp("singsong"))
{
message_vision(HIW"²»ÊÇ½Ğ$NÁ·Ï°"+me->query_temp("singsong")+"µÄÂğ?\n"NOR, me);
}
}
      call_out("sing_stage", 2, me, stage, i, sizeof(qupu[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
object ob1;
        int b1,b2;
if (!me)return;
   if(stage < size) {
            tell_object(me,qupu[i]["context"][stage]);
//   message_vision(qupu[i]["context"][stage], me);
   me->start_busy(1);
if (me->query("combat_exp") >1000000)
   call_out("sing_stage", 3, me, ++stage, i, size);
else    call_out("sing_stage", 1, me, ++stage, i, size);
   }
   else {
         message_vision(HIG"\n¹ıÁËÒ»»á£¬$NÊÖÖĞÇÙÉù½¥»º½¥Çá£¬ËÆºõÁ÷Ë®ãéãéÔ¶È¥£¬ÖÕÓÚ¸èÍêÇúÖÕ£¬¼ÅÈ»ÎŞÉù¡£\n"NOR, me);
if (!me)return;
if (!environment(me)) return;
        if (!ob1=present(me->query_temp("singn"),environment(this_player())))
{
message_vision(HIY"Ìı$N¸èµÄÈË×ßÁË£¬¿´À´$NÊÇ°×Ã¦ÁË!\n\n"NOR,me);
          return notify_fail(HIY"ÌıÄã¸èµÄÈË×ßÁË£¬¿´À´ÄãÊÇ°×Ã¦ÁË.\n"NOR);
}
if (qupu[i]["name"]==me->query_temp("singsong"))
{
        if (!ob1=present(me->query_temp("singn"),environment(this_player())))
{
message_vision(HIY"Ìı$N¸èµÄÈË×ßÁË£¬¿´À´$NÊÇ°×Ã¦ÁË!\n\n"NOR,me);
          return notify_fail(HIY"ÌıÄã¸èµÄÈË×ßÁË£¬¿´À´ÄãÊÇ°×Ã¦ÁË.\n"NOR);
}
b1=ob1->query("per");
b2=ob1->query("per")*2/3;
if (!b1) b1=20;
if (!b2) b1=10;
if (b1 >62) b1=62;
if (b2 >50) b2=50;
b1=random(b1);
b2=random(b2);

me->add("combat_exp", 12+b1);
me->add("potential", 8+b2);
message_vision(HIG"$nÌıÁËºó£¬ĞÄ¿õÉñÒÆ¡£¶Ô$NÎ¢Î¢Ò»Ğ¦!\n\n"NOR,me, ob1);
message_vision("$NµÄ¾­Ñé¼ÓÁË"+chinese_number(12+b1)+"µã¡£\n", me);
message_vision("$NµÄÇ±ÄÜ¼ÓÁË"+chinese_number(8+b2)+"µã¡£\n", me);
me->delete_temp("singsong");
me->delete_temp("singn");
}
    }
}