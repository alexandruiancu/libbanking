<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
		xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>
  <xsl:key name="children" match="class" use="@Parent"/>
  <xsl:attribute-set name="class_attributes">
    <xsl:attribute name="name"><xsl:value-of select="@name"/></xsl:attribute>
    <xsl:attribute name="Parent"><xsl:value-of select="@Parent"/></xsl:attribute>
    <xsl:attribute name="Detalii"><xsl:value-of select="@Detalii"/></xsl:attribute>
    <xsl:attribute name="Debit"><xsl:value-of select="@Debit"/></xsl:attribute>
    <xsl:attribute name="Credit"><xsl:value-of select="@Credit"/></xsl:attribute>
  </xsl:attribute-set>
  <xsl:template match="classes">
    <xsl:copy>
      <xsl:apply-templates select="key('children', '/')"/>
    </xsl:copy>
  </xsl:template>
  <xsl:template match="class">
    <xsl:variable name="child" select="@name"/>
    <xsl:text>&#xa;</xsl:text>
    <xsl:element name="class" use-attribute-sets="class_attributes">
      <xsl:apply-templates select="key('children', @name)"/>
    </xsl:element>
  </xsl:template>
  <xsl:template match="node()|@*">
    <xsl:copy>
      <xsl:apply-templates select="node()|@*"/>
    </xsl:copy>
  </xsl:template>
</xsl:stylesheet>
